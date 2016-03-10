using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Forms;
using System.Drawing;

namespace Launcher
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string chosenResolution = "1360 x 768";
        private string chosenMode = "windowed";
        private string musicVolume = "100";
        private string sfxVolume = "80";
        private double tempMusicSliderValue = 0;
        private double tempSFXSliderValue = 0;
        public MainWindow()
        {
            InitializeComponent();
            readScreenResolution();
        }

        private void readScreenResolution()
        {
            string width = Screen.PrimaryScreen.Bounds.Width.ToString();
            string height = Screen.PrimaryScreen.Bounds.Height.ToString();
            string resolutionString = (width + " x " + height);
            switch (resolutionString)
            {
                case "1360 x 768":
                    resolution.SelectedIndex = 0;
                    break;
                case "1366 x 768":
                    resolution.SelectedIndex = 1;
                    break;
                case "1440 x 900":
                    resolution.SelectedIndex = 2;
                    break;
                case "1600 x 900":
                    resolution.SelectedIndex = 3;
                    break;
                case "1600 x 1200":
                    resolution.SelectedIndex = 4;
                    break;
                case "1680 x 1050":
                    resolution.SelectedIndex = 5;
                    break;
                case "1920 x 1080":
                    resolution.SelectedIndex = 6;
                    break;
                case "1920 x 1200":
                    resolution.SelectedIndex = 7;
                    break;
                case "2560 x 1600":
                    resolution.SelectedIndex = 8;
                    break;
                case "3840 x 2160":
                    resolution.SelectedIndex = 9;
                    break;
            }
        }

        private void resolution_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            chosenResolution = (resolution.SelectedItem as ComboBoxItem).Content.ToString(); 
        }

        private void fullscreen_Checked(object sender, RoutedEventArgs e)
        {
            chosenMode = "fullscreen";
        }

        private void fullscreen_Unchecked(object sender, RoutedEventArgs e)
        {
            chosenMode = "windowed";
        }

        private void volume_SetMusic(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int value = (int)musicSlider.Value;
            musicVolume = value.ToString();
        }

        private void volume_SetSFX(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int value = (int)sfxSlider.Value;
            sfxVolume = value.ToString();
        }

        private void muteMusic(object sender, RoutedEventArgs e)
        {
            tempMusicSliderValue = musicSlider.Value;
            musicSlider.Value = 0;
            musicSlider.IsEnabled = false;
        }

        private void muteSFX(object sender, RoutedEventArgs e)
        {
            tempSFXSliderValue = sfxSlider.Value;
            sfxSlider.Value = 0;
            sfxSlider.IsEnabled = false;
        }

        private void unmuteMusic(object sender, RoutedEventArgs e)
        {
            musicSlider.Value = tempMusicSliderValue;
            musicSlider.IsEnabled = true;
        }

        private void unmuteSFX(object sender, RoutedEventArgs e)
        {
            sfxSlider.Value = tempSFXSliderValue;
            sfxSlider.IsEnabled = true;
        }

        private void changeChecks(object sender, RoutedEventArgs e)
        {

        }

        private void playButton_Click(object sender, RoutedEventArgs e)
        {
            System.IO.StreamWriter file = new System.IO.StreamWriter("config/settings.txt");
            file.WriteLine("Display resolution:\n");
            file.WriteLine(chosenResolution + "\n");
            file.WriteLine("Display Mode:\n");
            file.WriteLine(chosenMode);
            file.WriteLine("Music Volume:\n");
            file.WriteLine(musicVolume);
            file.WriteLine("SFX Volume:\n");
            file.WriteLine(sfxVolume);
            file.Close();
            Process theHutries = new Process();
            theHutries.StartInfo.FileName = "theHutries.exe";
            theHutries.Start();
        }
    }
}
