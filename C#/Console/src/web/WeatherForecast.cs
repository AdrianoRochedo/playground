namespace web;

public record WeatherForecast(DateTime Date, int TemperatureC, string? Summary)
{
    public int TemperatureF => 32 + (int) (TemperatureC / 0.5556);

    public override string ToString()
    {
        return $"Data => {Date.ToShortDateString()} | Temp => {TemperatureC} | Resumo => {Summary}";
    }
}
