using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using HolidaysViewer.Models;
using HolidaysViewer.Interfaces;

namespace HolidaysViewer.Controllers;

public class HomeController : Controller
{
    private readonly IHolidaysApiService _holidaysApiService;

    public HomeController(IHolidaysApiService holidaysApiService)
    {
        _holidaysApiService = holidaysApiService;
    }

    public async Task<IActionResult> Index(string countryCode = "US", int year = 2026)
    {
        var holidays = await _holidaysApiService.GetHolidays(countryCode, year);

        return View(holidays);
    }

    public IActionResult Privacy()
    {
        return View();
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}
