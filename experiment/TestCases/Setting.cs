using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenQA.Selenium;
using OpenQA.Selenium.Remote;
using OpenQA.Selenium.Support.PageObjects;

namespace ExperimentForLPP.Configurations
{
   public class Setting
    {
        DesiredCapabilities dc;
        RemoteWebDriver driver {get;set;}
        Application app;
        public Setting()
        {
            dc = new DesiredCapabilities();
            dc.SetCapability("app", @"E:\ВМК\5 курс\Диплом\Code\BackUp\GA_connect_with_test\Debug\form1.exe");
            driver = new RemoteWebDriver(new Uri("http://localhost:9999"), dc);
        }

        public Application open()
        {
            app = new Application(driver);
            return app;
        }
        public void close()
        {
            driver.Close();
        }

    }
}
