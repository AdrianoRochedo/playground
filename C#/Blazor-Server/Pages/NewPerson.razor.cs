using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Components;
using System.Net.Http;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Components.Authorization;
using Microsoft.AspNetCore.Components.Forms;
using Microsoft.AspNetCore.Components.Routing;
using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.Web.Virtualization;
using Microsoft.JSInterop;
using Blazor_Server;
using Blazor_Server.Shared;
using System.Diagnostics;

namespace Blazor_Server.Pages
{
    public partial class NewPerson
    {
        // https://docs.microsoft.com/en-us/aspnet/core/razor-pages/?view=aspnetcore-6.0&tabs=visual-studio
        // https://jonhilton.net/blazor-dynamic-components/

        readonly List<Type> _widgets = new()
        {
            typeof(Person), 
            typeof(ContaBancaria), 
        };

        private RenderFragment renderWidget(Type t) => builder =>
        {
            builder.OpenComponent(0, t);
            builder.CloseComponent();
        };

        protected override void OnInitialized()
        {
            base.OnInitialized();
            Debug.WriteLine("OnInitialized");
        }

        protected override void OnParametersSet()
        {
            base.OnParametersSet();
            Debug.WriteLine("OnParametersSet");
        }
    }
}