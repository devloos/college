using Microsoft.AspNetCore.Mvc;

namespace MovieList.Controllers;

public class HomeController : Controller
{
    public IActionResult Index()
    {
        return View();
    }
}
