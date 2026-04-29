# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Commands

```bash
# Run the app
dotnet run

# Build
dotnet build

# EF Core migrations
dotnet ef migrations add <MigrationName>
dotnet ef database update
dotnet ef migrations remove
```

## Architecture

ASP.NET Core MVC app (net10.0) that manages a movie list backed by a MySQL database via Entity Framework Core (Pomelo provider).

**Data flow:** `MovieContext` (EF DbContext) → `HomeController` → Razor Views

- `Models/MovieModel.cs` — `Movie` entity with `MovieId`, `Name`, `Year`, `Rating`
- `Models/MovieContextModel.cs` — `MovieContext` DbContext; seeds 3 default movies in `OnModelCreating`
- `Controllers/HomeController.cs` — MVC controller
- `Views/Home/Index.cshtml` — main view
- `Program.cs` — registers `MovieContext` with MySQL connection string from `appsettings.json`

**Database:** MySQL on `127.0.0.1:3306`, database name `Movies`, configured in `appsettings.json` under `ConnectionStrings.MovieContext`. The Migrations folder was deleted from the repo (`git status` shows them as deleted) — re-run `dotnet ef migrations add Initial` and `dotnet ef database update` to recreate.
