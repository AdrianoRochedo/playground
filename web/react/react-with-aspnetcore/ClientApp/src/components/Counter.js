import React, { Component } from 'react';

export class Counter extends Component
{
    static displayName = Counter.name;

    constructor(props)
    {
        super(props);

        this.state =
        {
            currentCount_1: 0,
            currentCount_2: 5,
        };

        // ao fazer o BIND eu transformo minhas funcoes internas em handlers de eventos
        this.incrementCounter_1 = this.incrementCounter_1.bind(this);
        this.incrementCounter_2 = this.incrementCounter_2.bind(this);
        this.incrementCounters  = this.incrementCounters.bind(this);
    }

    incrementCounter_1()
    {
        this.setState({
            currentCount_1: this.state.currentCount_1 + 1,
            currentCount_2: this.state.currentCount_2,
        });
    }

    incrementCounter_2()
    {
        this.setState({
            currentCount_1: this.state.currentCount_1,
            currentCount_2: this.state.currentCount_2 + 3,
        });
    }

    incrementCounters()
    {
        // ERRO: desta maneira .... quando separados ... somente o segundo counter eh incrementado !
        //this.incrementCounter_1();
        //this.incrementCounter_2();

        // CORRETO: operacao atomica
        this.setState({
            currentCount_1: this.state.currentCount_1 + 1,
            currentCount_2: this.state.currentCount_2 + 3,
        });
    }

    // https://localhost:44493/fetch-data
    // https://localhost:44493/weatherforecast

    render()
    {
        return (
            <div>
                <h1>Counter</h1>

                <p>This is a simple example of a React component.</p>

                <p aria-live="polite">Current count 1: <strong>{this.state.currentCount_1}</strong></p>
                <p aria-live="polite">Current count 2: <strong>{this.state.currentCount_2}</strong></p>

                <button className="btn btn-primary" onClick={this.incrementCounters}>Increment</button>
            </div>
        );
    }
}
