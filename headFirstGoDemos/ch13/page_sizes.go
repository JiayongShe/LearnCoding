package ch13

import (
	"fmt"
	"io"
	"log"
	"net/http"
)

type Page struct {
	URL  string
	Size int
}

func responseSize(url string, channel chan Page) {
	fmt.Println("Getting", url)
	response, err := http.Get(url)
	if err != nil {
		log.Fatal(err)
	}
	defer response.Body.Close()
	body, err := io.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(url, "before channel send size:", len(body))
	channel <- Page{URL: url, Size: len(body)}
	fmt.Println(url, "after channel send size:", len(body))
}

func ChannelGetPageSize() {
	urls := []string{"https://example.com/", "https://go.dev/", "https://go.dev/doc"}
	pages := make(chan Page)
	// pages := make(chan Page, len(urls))
	for _, url := range urls {
		go responseSize(url, pages)
	}
	// close(pages)
	for i := 0; i < len(urls); i++ {
		page := <-pages
		fmt.Printf("%s: %d\n", page.URL, page.Size)
	}
	// for page := range pages {
	// 	fmt.Printf("%s: %d\n", page.URL, page.Size)
	// }
}
