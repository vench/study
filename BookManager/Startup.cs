using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.HttpsPolicy;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore.Sqlite;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using BookManager.Models;

namespace BookManager
{
    public class Startup
    {
        public IConfiguration Config { get; }
        public Startup(IConfiguration config) { Config = config; }

        public void Configure(IApplicationBuilder app, IHostingEnvironment env)
        {
            app
                .UseStaticFiles()
                .UseMvc()
                .UseFileServer()
                .Run(async (c) => await c.Response.WriteAsync("Middleware could not handle this request..."));
        }

        public void ConfigureServices(IServiceCollection services)
        {
            services
                .AddDbContext<BookDbContext>()
                .AddMvc();
        }
    }
}
