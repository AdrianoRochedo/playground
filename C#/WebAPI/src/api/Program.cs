var builder = WebApplication.CreateBuilder(args);

#region SERVICES

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

#endregion

var app = builder.Build();

#region CONFIG

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

#endregion

#region ROUTES

app.MapGet
(
    "/weatherforecast", 
    () => Services.WeatherForecastServices.GetWeatherForecast()
);

#endregion

app.Run();