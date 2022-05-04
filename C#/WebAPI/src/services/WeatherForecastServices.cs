namespace Services;

using Entities;

internal static class WeatherForecastServices
{ 
    private static readonly string[] summaries = new[]
    {
        "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
    };

    /// <summary>
    /// retorna um array com 5 elementos do tipo "WeatherForecast" com dados aleatorios
    /// </summary>
    internal static WeatherForecast[] GetWeatherForecast()
    {
        var forecast =  Enumerable.Range(1, 5).Select(index =>
        new WeatherForecast
        (
            DateTime.Now.AddDays(index),
            Random.Shared.Next(-20, 55),
            summaries[Random.Shared.Next(summaries.Length)]
        ))
        .ToArray();

        return forecast;
    }
}