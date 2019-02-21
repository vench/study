using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Sqlite;
using Microsoft.Data.Sqlite;

namespace BookManager.Models
{
    public class BookDbContext : DbContext
    {
        public BookDbContext()
        {
        }

        public DbSet<Book> Books { get; set; }
        public DbSet<Author> Authors { get; set; }
        public DbSet<Category> Categories { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            var connectionStringBuilder = new SqliteConnectionStringBuilder { DataSource = "MyDb.db" };
            var connectionString = connectionStringBuilder.ToString();
            var connection = new SqliteConnection(connectionString);

            optionsBuilder.UseSqlite(connection);
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder
                .Entity<Book>()
                .Property(x => x.Uri)
                .HasConversion(x => x.ToString(), x => strToUri(x));
        }

        private Uri strToUri(string str) {
            Uri uri;

            if (!Uri.TryCreate(str, UriKind.RelativeOrAbsolute, out uri))

            {
                return new Uri("");
            }


            return uri;
        }
    }
}
