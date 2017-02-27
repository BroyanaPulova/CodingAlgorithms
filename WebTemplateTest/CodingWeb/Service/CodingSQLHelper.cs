using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace CodingWeb.Service
{
    public class CodingSQLHelper
    {
        public static int SetKey(string data)
        {
            try
            {
                SqlConnection connection = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\CodingWeb\App_Data\CodingHeper.mdf;Integrated Security=True");
                connection.Open();

                SqlCommand command = new SqlCommand(string.Format("Insert into CodingHelper(Data) Values('{0}'); SELECT CAST(scope_identity() AS int)", data), connection);

                int result = (int)command.ExecuteScalar();

                connection.Close();

                return result;
            }
            catch(Exception exc)
            {
                return -1;
            }
        }

        public static string GetValue(int key)
        {
            SqlConnection connection = new SqlConnection(@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\Boryana\Desktop\Дипломна\WebTemplateTest\WebTemplateTest\CodingWeb\App_Data\CodingHeper.mdf;Integrated Security=True");
            connection.Open();

            SqlCommand command = new SqlCommand(string.Format("Select Data From CodingHelper Where Id = {0}", key), connection);
            SqlDataReader reader = command.ExecuteReader();

            string result = string.Empty;

            while (reader.Read())
            {
                result = (string)reader[0];
            }

            reader.Close();
            connection.Close();

            return result;
        }
    }
}