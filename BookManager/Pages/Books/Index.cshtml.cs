using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using BookManager.Models;
using BookManager.Hint;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore; 


namespace BookManager.Pages.Books
{
    public class IndexModel : PageModel
    {

        readonly BookDbContext db;
        readonly int pageSize;
        public PaginatedList<Book> Books { get; set; }
        public IList<Author> Authors {get; private set;}
        public IList<Category> Categories { get; private set; }
        public string Sort { get; set; } 
        public string Filter { get; set; }
        public int Filter_author { get; set; }
        public int Filter_categorie { get; set; }

        public IndexModel(BookDbContext ctx)
        {
            db = ctx;
            DbInitializer.Seed(db);
            pageSize = 5;
        }
 

        public async Task OnGetAsync(string sort, string filter, string search, int? pageID, int Filter_author, int Filter_categorie)
        {

            if (search != null)
                pageID = 1;
            else
                search = filter;
            Filter = search; 
            Sort = sort;

            this.Filter_author = Filter_author;
            this.Filter_categorie = Filter_categorie;

            var books = db.Books.Include("Author").AsQueryable();
            if (!string.IsNullOrEmpty(search))
            {
                books = books.Where(x => x.Title.Contains(search));
            }
            if(Filter_author > 0) {
                books = books.Where(x => x.AuthorId == Filter_author);
            }
            if(Filter_categorie > 0) {
                books = books.Where(x => x.CategoryId == Filter_categorie);
            }

            switch (sort)
            {
                case "id":
                    books = books.OrderBy(x => x.Id);
                    break;
                case "idDesc":
                    books = books.OrderByDescending(x => x.Id);
                    break;
                case "title":
                    books = books.OrderBy(x => x.Title);
                    break;
                case "titleDesc":
                    books = books.OrderByDescending(x => x.Title);
                    break;
                case "authorDesc":
                    books = books.OrderByDescending(x => x.Author.FullName);
                    break;
                case "author": 
                    books = books.OrderBy(x => x.Author.FullName); 
                    break;
                default: books = books.OrderBy(x => x.Id); break;
            }
            Books = await PaginatedList<Book>.CreateAsync(books, pageID ?? 1, pageSize);
 
            Authors = await db.Authors.AsNoTracking().ToListAsync();
            Categories = await db.Categories.AsNoTracking().ToListAsync();
        }

    }
}
