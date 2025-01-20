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

func stockDataHandler(w http.ResponseWriter, r *http.Request) {
	apiKey := os.Getenv("ALPHA_VANTAGE_API_KEY")
	if apiKey == "" {
		http.Error(w, "API key is not set", http.StatusInternalServerError)
		return
	}

	symbol := r.URL.Query().Get("symbol")
	if symbol == "" {
		http.Error(w, "Symbol is required", http.StatusBadRequest)
		return
	}

	timeSeries, err := fetchStockData(symbol, apiKey)
	if err != nil {
		http.Error(w, fmt.Sprintf("Error fetching stock data: %v", err), http.StatusInternalServerError)
		return
	}

	w.Header().Set("Content-Type", "application/json")

	err = json.NewEncoder(w).Encode(timeSeries)
	if err != nil {
		http.Error(w, fmt.Sprintf("Error encoding JSON: %v", err), http.StatusInternalServerError)
		return
	}
}

func main() {
	err := godotenv.Load()
	if err != nil {
		log.Fatal("Error loading .env file")
	}

	http.HandleFunc("/stockdata", stockDataHandler)

	log.Println("Server is starting...")
	log.Fatal(http.ListenAndServe(":8080", nil))

}

