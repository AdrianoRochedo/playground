using static CommunityToolkit.Maui.Markup.GridRowsColumns;

namespace AdvancedApp.Views;

public partial class WebViewPage : ContentPage
{
	public WebViewPage(WebViewViewModel viewModel)
	{
		BindingContext = viewModel;

        Content = new Grid
        {
            RowDefinitions = Rows.Define(Star, Auto),
            Children =
            {
                new WebView().Assign(out WebView webView)
                             .Bind(WebView.SourceProperty, nameof(WebViewViewModel.Source))
                             .Bind(WebView.NavigationProperty, nameof(WebViewViewModel.WebViewNavigatedCommand)),
                new HorizontalStackLayout
                {
                    Spacing = 12,
                    Children =
                    {
                        new Button().Text("Back")
                                     .Bind(Button.IsEnabledProperty, WebView.CanGoBackProperty.PropertyName, source: webView)
                                     .BindCommand(nameof(WebViewViewModel.NavigateBackCommand), parameterSource: webView),
                        new Button().Text("Forward")
                                    .Bind(Button.IsEnabledProperty, WebView.CanGoForwardProperty.PropertyName, source: webView)
                                    .BindCommand(nameof(WebViewViewModel.NavigateForwardCommand), parameterSource: webView),
                        new Button().Text("Refresh")
                                    .BindCommand(nameof(WebViewViewModel.RefreshPageCommand), parameterSource: webView),
                        new Button().Text("Open in browser")
                                    .BindCommand(nameof(WebViewViewModel.OpenInBrowserCommand)),
                    },
                }.CenterHorizontal()
                 .Row(1),
            },
        };
    }
}
