namespace AdvancedApp;

public class AppShell : Shell
{
	public AppShell(MainPage Main, ListDetailPage ListDetail, WebViewPage WebView, SamplePage Sample)
	{
		Routing.RegisterRoute(nameof(ListDetailDetailPage), typeof(ListDetailDetailPage));
		Items.Add(new ShellContent { Title = "Main", Icon = ImageSource.FromFile("iconblank.png"), Content = Main });
		Items.Add(new ShellContent { Title = "ListDetail", Icon = ImageSource.FromFile("iconlistdetail.png"), Content = ListDetail });
		Items.Add(new ShellContent { Title = "WebView", Icon = ImageSource.FromFile("iconwebview.png"), Content = WebView });
		Items.Add(new ShellContent { Title = "Sample", Icon = ImageSource.FromFile("iconsample.png"), Content = Sample });
	}
}
