using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using BookManager.Hint;

namespace BookManager.Pages.Authors
{
    public class IndexModel : PageModel
    {
        readonly BookDbContext db;
        readonly int pageSize;
        public PaginatedList<Author> Authors { get; set; }
        public string Sort { get; set; }
        public string Filter { get; set; }

        public IndexModel(BookDbContext ctx)
        {
            db = ctx;
            pageSize = 5;
        }

        public async Task OnGetAsync(string sort, string filter, string search, int? pageID)
        {

            if (search != null)
                pageID = 1;
            else
                search = filter;
            Filter = search;
            Sort = sort;

            var authors = db.Authors.AsQueryable();
            if (!string.IsNullOrEmpty(search))
                authors = authors.Where(x => x.FullName.Contains(search));

            switch (sort)
            {
                case "id":
                    authors = authors.OrderBy(x => x.Id);
                    break;
                case "idDesc":
                    authors = authors.OrderByDescending(x => x.Id);
                    break;
                case "name":
                    authors = authors.OrderBy(x => x.FullName);
                    break;
                case "nameDesc":
                    authors = authors.OrderByDescending(x => x.FullName);
                    break;
                case "email":
                    authors = authors.OrderBy(x => x.Email);
                    break;
                case "emailDesc":
                    authors = authors.OrderByDescending(x => x.Email);
                    break;
                default: authors = authors.OrderBy(x => x.Id); break;
            }
            Authors = await PaginatedList<Author>.CreateAsync(authors, pageID ?? 1, pageSize);
        }
    }
}
