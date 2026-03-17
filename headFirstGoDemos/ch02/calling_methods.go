package ch02

import (
	"fmt"
	"strings"
	"time"
)

func CallingMethods() {
	var now time.Time = time.Now()
	var year int = now.Year()
	fmt.Println(year)
	broken := "G# r#cks!"
	replacer := strings.NewReplacer("#", "o")
	fixed := replacer.Replace(broken)
	fmt.Println(fixed)
	fmt.Println()
}
