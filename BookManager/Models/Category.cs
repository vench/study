using System;
namespace BookManager.Models
{
    public class Category
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string RowVersion{ get; set; }

        public Category()
        {
        }
    }
}
