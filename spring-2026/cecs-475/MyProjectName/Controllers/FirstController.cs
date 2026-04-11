using Microsoft.AspNetCore.Mvc;

namespace MyProjectName.Controllers;

public class FirstController : Controller
{
  public string Index()
  {
    return "Hello World";
  }

  public IActionResult Hello()
  {
    return View();
  }
}