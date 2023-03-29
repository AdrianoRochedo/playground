import React, { Component } from 'react';

export class FetchData extends Component
{
    static displayName = FetchData.name;

    constructor(props)
    {
        super(props);
        this.state = { forecasts: [], loading: true };
    }

    // chamado quando o componente esta "pronto"
    componentDidMount()
    {
        this.populateWeatherData();
    }

    static renderForecastsTable(forecasts)
    {
        return (
            <table className="table table-striped" aria-labelledby="tableLabel">
                <thead>
                    <tr>
                        <th>Date</th>
                        <th>Temp. (C)</th>
                        <th>Temp. (F)</th>
                        <th>Summary</th>
                    </tr>
                </thead>
                <tbody>
                    {forecasts.map(forecast =>
                        <tr key={forecast.date}>
                            <td>{forecast.date}</td>
                            <td>{forecast.temperatureC}</td>
                            <td>{forecast.temperatureF}</td>
                            <td>{forecast.summary}</td>
                        </tr>
                    )}
                </tbody>
            </table>
        );
    }

    render()
    {
        let contents = this.state.loading
            ? <p><em>Loading...</em></p>
            : FetchData.renderForecastsTable(this.state.forecasts);

        return (
            <div>
                <h1 id="tableLabel">Weather forecast</h1>
                <p>This component demonstrates fetching data from the server.</p>
                {contents}
            </div>
        );
    }

    async populateWeatherData()
    {
        // abaixo eh o "padrao" 
        //const response = await fetch('weatherforecast');

        // para funcionar com caminho inteiro, no server eh preciso da seguinte linha:
        // app.UseCors(options => { options.AllowAnyOrigin(); });
        const response = await fetch('https://localhost:7054/weatherforecast');

        const data = await response.json();
        this.setState({ forecasts: data, loading: false });
    }
}
