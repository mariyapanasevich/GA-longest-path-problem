using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExperimentForLPP
{
    using System;

    using OpenQA.Selenium;
    using OpenQA.Selenium.Remote;
    using OpenQA.Selenium.Support.PageObjects;

    public class Program
    {
        private static void Main(string[] args)
        {
            var dc = new DesiredCapabilities();
            dc.SetCapability("app", @"E:/BackUp/GA/Debug/form1.exe");
            var driver = new RemoteWebDriver(new Uri("http://localhost:9999"), dc);
            var app = new Application(driver);
            app.longestPathinBetweenVertex();
           

            driver.Close();
        }

    }
}