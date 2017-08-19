using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;
using Dapper;
using System.Configuration;
using ExperimentForLPP.Classes;

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


        public static GaInAllPath GetTestData()
        {
            using (var connection = new OleDbConnection(TestDataFileConnection()))
            {
                connection.Open();
                var query = string.Format("select* from [GaInAllPath$]");
                var value = connection.Query<GaInAllPath>(query).FirstOrDefault();
                

                connection.Close();
                return value;
            }
        }


     


    }
}
