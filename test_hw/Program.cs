using Microsoft.AspNetCore;
using Microsoft.AspNetCore.Hosting;

namespace Messages
{
    public class Program
    {
        public static void Main()
        {
            WebHost
                .CreateDefaultBuilder()
                .UseStartup<Startup>()
                .Build()
                .Run();
        }
    }
}