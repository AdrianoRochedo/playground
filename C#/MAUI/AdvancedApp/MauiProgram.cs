﻿namespace AdvancedApp;

public static class MauiProgram
{
	public static MauiApp CreateMauiApp()
	{
		var builder = MauiApp.CreateBuilder();

		builder
			.UseMauiApp<App>()
			.UseMauiCommunityToolkit()
			.UseMauiCommunityToolkitMarkup()
			.ConfigureFonts(fonts =>
			{
				fonts.AddFont("OpenSans-Regular.ttf"  , "OpenSansRegular");
				fonts.AddFont("OpenSans-Semibold.ttf" , "OpenSansSemibold");
			});

		builder.Services.AddSingleton<App>();
		
		builder.Services.AddTransient<AppShell>();
		builder.Services.AddTransient<SampleDataService>();
		builder.Services.AddTransient<ListDetailDetailPage>();
		builder.Services.AddTransient<ListDetailDetailViewModel>();
		builder.Services.AddTransient<MainPage, MainViewModel>();
		builder.Services.AddTransient<ListDetailPage, ListDetailViewModel>();
		builder.Services.AddTransient<WebViewPage, WebViewViewModel>();
		builder.Services.AddTransient<SamplePage, SampleViewModel>();

		return builder.Build();
	}
}