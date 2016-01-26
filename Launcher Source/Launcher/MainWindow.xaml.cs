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

namespace Launcher
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string chosenResolution = "1360 x 768";
        private string chosenMode = "windowed";
        public MainWindow()
        {
            InitializeComponent();
        }

        private void resolution_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            chosenResolution = (resolution.SelectedItem as ComboBoxItem).Content.ToString();
            //MessageBox.Show(chosenResolution);  
        }

        private void fullscreen_Checked(object sender, RoutedEventArgs e)
        {
            chosenMode = "fullscreen";
            //MessageBox.Show(chosenMode);
        }

        private void fullscreen_Unchecked(object sender, RoutedEventArgs e)
        {
            chosenMode = "windowed";
            //MessageBox.Show(chosenMode);
        }

        private void playButton_Click(object sender, RoutedEventArgs e)
        {
            System.IO.StreamWriter file = new System.IO.StreamWriter("config/settings.txt");
            file.WriteLine("Display resolution:\n");
            file.WriteLine(chosenResolution + "\n");
            file.WriteLine("Display Mode:\n");
            file.WriteLine(chosenMode);
            file.Close();
            Process theHutries = new Process();
            theHutries.StartInfo.FileName = "theHutries.exe";
            //theHutries.StartInfo.Arguments = "mytextfile.txt";
            theHutries.Start();

        }
    }
}
