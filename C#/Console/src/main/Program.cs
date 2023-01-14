using static System.Console;

var wfs = await web.WeatherForecastsServices.GetAsync();
foreach(var wf in wfs) WriteLine(wf);

ReadKey();
