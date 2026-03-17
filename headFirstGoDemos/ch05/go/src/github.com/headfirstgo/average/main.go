// average calculates the average of several numbers.
package ch05

import (
	"fmt"
	"headFirstGoDemos/ch05/go/src/github.com/headfirstgo/datafile"
	"log"
)

func CalcAverage() {
	numbers, err := datafile.GetFloats(
		"ch05/go/src/github.com/headfirstgo/average/data.txt")
	if err != nil {
		log.Fatal(err)
	}
	var sum float64 = 0
	for _, number := range numbers {
		sum += number
	}
	sampleCount := float64(len(numbers))
	fmt.Printf("Average: %0.2f\n", sum/sampleCount)
}
