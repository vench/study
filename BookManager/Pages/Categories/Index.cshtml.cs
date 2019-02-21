using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using BookManager.Models;
using BookManager.Hint;

namespace BookManager.Pages.Categories
{


    public class IndexModel : PageModel
    {
        readonly BookDbContext db;
        readonly int pageSize;
        public PaginatedList<Category> Categories { get; set; }
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

            var categories = db.Categories.AsQueryable();
            if (!string.IsNullOrEmpty(search))
                categories = categories.Where(x => x.Name.Contains(search));

            switch (sort)
            {
                case "id":
                    categories = categories.OrderBy(x => x.Id);
                    break;
                case "idDesc":
                    categories = categories.OrderByDescending(x => x.Id);
                    break;
                case "name":
                    categories = categories.OrderBy(x => x.Name);
                    break;
                case "nameDesc":
                    categories = categories.OrderByDescending(x => x.Name);
                    break;
                case "rowVersion":
                    categories = categories.OrderBy(x => x.RowVersion);
                    break;
                case "rowVersionDesc":
                    categories = categories.OrderByDescending(x => x.RowVersion);
                    break;

                default: categories = categories.OrderBy(x => x.Id); break;
            }
            Categories = await PaginatedList<Category>.CreateAsync(categories, pageID ?? 1, pageSize);
        }
    }
}
