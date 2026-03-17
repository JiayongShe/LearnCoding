package ch07

import (
	"fmt"
	"headFirstGoDemos/ch07/go/src/github.com/headfirstgo/datafile"
	"log"
)

func CalcVote() {
	lines, err := datafile.GetStrings("ch07/go/bin/votes.txt")
	if err != nil {
		log.Fatal(err)
	}
	counts := make(map[string]int)
	for _, line := range lines {
		counts[line]++
	}
	for name, count := range counts {
		fmt.Printf("Votes for %s: %d\n", name, count)
	}
}
