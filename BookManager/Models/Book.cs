using System;
using Microsoft.EntityFrameworkCore;

namespace BookManager.Models
{
    public class Book
    {

        public int Id { get; set; }
        public string Title { get; set; }
        public Uri Uri { get; set; }
        public Category Category { get; set; }
        public Author Author { get; set; }
        public int CategoryId { get; set; }
        public int AuthorId { get; set; }

        public Book()
        {
        }


    }
}
