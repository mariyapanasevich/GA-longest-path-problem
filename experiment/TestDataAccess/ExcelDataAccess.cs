using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;
using Dapper;
using System.Configuration;
using ExperimentForLPP.Classes;
using System.Collections.Generic;

namespace ExperimentForLPP
{
    class ExcelDataAccess
    {
        public static string TestDataFileConnection()
        {
            var fileName = ConfigurationManager.AppSettings["TestDataSheetPath"];
            var con = string.Format(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source = {0}; Extended Properties=Excel 12.0;", fileName);
            return con;
        }

        public static T GetTestData<T>(int data)
        {
            using (var connection = new OleDbConnection(TestDataFileConnection()))
            {
                connection.Open();
             
                string query = "";
                if (data == 1)
                {
                  query = string.Format("select * from [GaInAllPath$]");
                }
                else if (data == 2)
                {
                    query = string.Format("select * from [GaBetweenVertex$]");
                }
             
                var value = connection.Query<T>(query).FirstOrDefault();
                connection.Close();
                return (T) Convert.ChangeType(value, typeof(T));
            }
        }
    }
}
