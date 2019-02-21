using System;
namespace BookManager.Models
{
    public class Author
    {
        public int Id { get; set; }
        public string LastName { get; set; }
        public string ForeName { get; set; }
        public string Email { get; set; }
        public string FullName { 
            get {
                return ForeName + " " + LastName;
            }
        }


        public Author() { }
    }
}
