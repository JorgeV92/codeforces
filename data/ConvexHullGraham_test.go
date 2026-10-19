package data

import (
	"math/rand"
	"reflect"
	"testing"
)

func TestHull(t *testing.T) {
	tests := []struct {
		name   string
		points []Point
		want   []Point
	}{
		{"empty", nil, nil},
		{"single", []Point{{2, 3}}, []Point{{2, 3}}},
		{"identical", []Point{{2, 3}, {2, 3}, {2, 3}}, []Point{{2, 3}}},
		{"two", []Point{{3, 1}, {-1, 2}}, []Point{{-1, 2}, {3, 1}}},
		{"horizontal", []Point{{2, 0}, {0, 0}, {1, 0}, {2, 0}}, []Point{{0, 0}, {2, 0}}},
		{"vertical", []Point{{0, 2}, {0, -1}, {0, 0}}, []Point{{0, -1}, {0, 2}}},
		{"diagonal", []Point{{2, -2}, {-2, 2}, {0, 0}}, []Point{{-2, 2}, {2, -2}}},
		{
			"square with duplicates, edge points, and interior points",
			[]Point{{1, 1}, {2, 2}, {0, 0}, {0, 2}, {2, 0}, {1, 0}, {2, 1}, {0, 1}, {1, 2}, {2, 2}, {0, 0}},
			[]Point{{0, 0}, {2, 0}, {2, 2}, {0, 2}},
		},
		{
			"angles above and below pivot",
			[]Point{{0, 0}, {1, -2}, {3, 0}, {1, 2}, {1, 0}},
			[]Point{{0, 0}, {1, -2}, {3, 0}, {1, 2}},
		},
		{
			"fractional coordinates",
			[]Point{{0.5, 0.5}, {1.5, 1.5}, {-0.5, -0.5}, {1.5, -0.5}, {-0.5, 1.5}},
			[]Point{{-0.5, -0.5}, {1.5, -0.5}, {1.5, 1.5}, {-0.5, 1.5}},
		},
	}
	for _, tc := range tests {
		t.Run(tc.name, func(t *testing.T) {
			before := append([]Point(nil), tc.points...)
			if got := Hull(tc.points); !reflect.DeepEqual(got, tc.want) {
				t.Fatalf("Hull() = %v, want %v", got, tc.want)
			}
			indices := HullInd(tc.points)
			if len(indices) != len(tc.want) {
				t.Fatalf("HullInd() = %v, want %d indices", indices, len(tc.want))
			}
			for i, index := range indices {
				if index < 0 || index >= len(tc.points) || tc.points[index] != tc.want[i] {
					t.Fatalf("HullInd()[%d] = %d, want index of %v", i, index, tc.want[i])
				}
			}
			if !reflect.DeepEqual(tc.points, before) {
				t.Fatal("input points were modified")
			}
		})
	}
}

func TestHullAgainstGiftWrapping(t *testing.T) {
	rng := rand.New(rand.NewSource(343))
	for trial := 0; trial < 1000; trial++ {
		points := make([]Point, rng.Intn(40))
		for i := range points {
			points[i] = Point{Coordinate(rng.Intn(11) - 5), Coordinate(rng.Intn(11) - 5)}
		}
		want := giftWrapping(points)
		if got := Hull(points); !reflect.DeepEqual(got, want) {
			t.Fatalf("points = %v: Hull() = %v, want %v", points, got, want)
		}
	}
}

// An independent O(n*h) oracle: choose each supporting edge by checking all
// points, without angular sorting or a stack.
func giftWrapping(points []Point) []Point {
	if len(points) == 0 {
		return nil
	}
	start := points[0]
	for _, p := range points {
		if p.X < start.X || (p.X == start.X && p.Y < start.Y) {
			start = p
		}
	}
	var result []Point
	for current := start; ; {
		result = append(result, current)
		next := current
		for _, p := range points {
			dx, dy := next.X-current.X, next.Y-current.Y
			px, py := p.X-current.X, p.Y-current.Y
			turn := dx*py - dy*px
			if next == current || turn < 0 || (turn == 0 && px*px+py*py > dx*dx+dy*dy) {
				next = p
			}
		}
		if next == start {
			return result
		}
		current = next
	}
}
