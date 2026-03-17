package test

import (
	"fmt"
	"sync"
)

func TestSyncWaitGroup() {
	resultChan := make(chan string, 3)
	wg := new(sync.WaitGroup)
	for i := 0; i < 3; i++ {
		wg.Add(1)
		go func(s int) {
			defer func() {
				wg.Done()
			}()
			fmt.Println("***sending value***", s)
			resultChan <- fmt.Sprintf("result %d", s)
		}(i)
	}
	wg.Wait()
	close(resultChan)
	for resultItem := range resultChan {
		fmt.Println(resultItem)
	}

	// for i := 0; i < 4; i++ {
	// 	fmt.Println("i:", i, <-resultChan)
	// }
}

func TestInputOutput() {}
