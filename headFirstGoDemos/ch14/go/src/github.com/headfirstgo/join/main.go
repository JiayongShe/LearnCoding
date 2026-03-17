package ch14

import (
	"fmt"
	"headFirstGoDemos/ch14/go/src/github.com/headfirstgo/prose"
)

func Join() {
	phrases := []string{"my parents", "a rodeo clown"}
	fmt.Println("A photo of", prose.JoinWithCommas(phrases))
	phrases = []string{"my parents", "a rodeo clown", "a prize bull"}
	fmt.Println("A photo of", prose.JoinWithCommas(phrases))
}
