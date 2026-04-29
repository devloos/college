using System.ComponentModel.DataAnnotations;

namespace MovieList.Models;

public class Genre
{
  // EF will instruct the database to automatically generate this value
  public string GenreId { get; set; } = string.Empty;
  public string Name { get; set; } = string.Empty;

}