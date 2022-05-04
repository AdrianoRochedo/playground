using System.Net.Http.Json;
using System.Net.Http.Headers;

namespace web;

public static class WeatherForecastsServices
{
    private static HttpClient client;

    static WeatherForecastsServices()
    {
        client = new HttpClient();
        client.BaseAddress = new Uri("http://localhost:5087/");
        client.DefaultRequestHeaders.Accept.Clear();
        client.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));
    }

    public static async Task<WeatherForecast[]> GetAsync()
    {
        var wf = await client.GetFromJsonAsync<WeatherForecast[]>("WeatherForecast");

        if (wf == null || wf.Length == 0)
            throw new InvalidOperationException();

        return wf;
    }
}
