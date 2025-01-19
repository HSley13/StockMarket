package main

import (
	"encoding/json"
	"fmt"
	"github.com/joho/godotenv"
	"io"
	"log"
	"net/http"
	"os"
)

type StockTimeSeries struct {
	MetaData struct {
		Information   string `json:"1. Information"`
		Symbol        string `json:"2. Symbol"`
		LastRefreshed string `json:"3. Last Refreshed"`
	} `json:"Meta Data"`
	TimeSeries map[string]struct {
		Open   string `json:"1. open"`
		High   string `json:"2. high"`
		Low    string `json:"3. low"`
		Close  string `json:"4. close"`
		Volume string `json:"5. volume"`
	} `json:"Time Series (Daily)"`
}

func fetchStockData(symbol string, apiKey string) (*StockTimeSeries, error) {
	url := fmt.Sprintf("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=%s&outputsize=compact&apikey=%s", symbol, apiKey)

	resp, err := http.Get(url)
	if err != nil {
		return nil, fmt.Errorf("Error fetching stock data: %v", err)
	}
	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)
	if err != nil {
		return nil, fmt.Errorf("Error reading response body: %v", err)
	}

	var timeSeries StockTimeSeries
	err = json.Unmarshal(body, &timeSeries)
	if err != nil {
		return nil, fmt.Errorf("Error unmarshalling JSON: %v", err)
	}

	return &timeSeries, nil
}

func main() {
	err := godotenv.Load()
	if err != nil {
		log.Fatal("Error loading .env file")
	}

	apiKey := os.Getenv("ALPHA_VANTAGE_API_KEY")
	if apiKey == "" {
		log.Fatal("API key is not set in the environment variables.")
	}

	symbol := "AAPL"
	timeSeries, err := fetchStockData(symbol, apiKey)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error fetching stock data: %v\n", err)
		os.Exit(1)
	}

	fmt.Printf("Stock Information for %s\n", timeSeries.MetaData.Symbol)

	for date, data := range timeSeries.TimeSeries {
		fmt.Printf("Date: %s\n", date)
		fmt.Printf("Open: %s\n", data.Open)
		fmt.Printf("High: %s\n", data.High)
		fmt.Printf("Low: %s\n", data.Low)
		fmt.Printf("Close: %s\n", data.Close)
		fmt.Printf("Volume: %s\n", data.Volume)
		fmt.Println()
	}
}
