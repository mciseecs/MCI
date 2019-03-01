using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SQLite;
using NUMICIS.Classes;
namespace NUMICIS
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void metroButton1_Click(object sender, EventArgs e)
        {


            SQLiteConnection conn = new SQLiteConnection (@"Data Source=F:\MCIDatabase.db");
            conn.Open();

            SQLiteCommand cmd;

            string query = "insert into USER (Name, Password) values ('" + this.txtUserName.Text + "', '" + this.txtPassword.Text + "')";
            SQLiteCommand createCommand = new SQLiteCommand(query, conn);
            createCommand.ExecuteNonQuery();

            if (this.txtPassword.Text == this.metroTextBox1.Text)
            {
                MessageBox.Show("You are Registered!");


            }

            else {
                MessageBox.Show("Password Mismatch! Re-enter");
            }


            conn.Close();






        }
    }
}
