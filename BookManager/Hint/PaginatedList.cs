using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace BookManager.Hint
{
    public class PaginatedList<T> : List<T>
    {
        public int PageID { get; private set; }
        public int Total { get; private set; }
        public int TotalPages { get; private set; }
        public bool HasPreviousPage { get { return PageID > 1; } }
        public bool HasNextPage { get { return PageID < TotalPages; } }


        public PaginatedList(List<T> list, int count, int pageId, int pageSize)
        {
            PageID = pageId;
            Total = count;
            TotalPages = (int)Math.Ceiling(count / (double)pageSize);
            AddRange(list);
        }

        public static async Task<PaginatedList<T>> CreateAsync(IQueryable<T> list, int pageId, int pageSize)
        {
            var count = await list.CountAsync();
            var items = await list.Skip((pageId - 1) * pageSize).Take(pageSize).ToListAsync();
            return new PaginatedList<T>(items, count, pageId, pageSize);
        }
    }
}
