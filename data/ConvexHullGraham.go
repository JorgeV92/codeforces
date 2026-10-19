package data

import "sort"

// Coordinate matches the source's default point type. For integer geometry,
// this alias can be changed to int64 if all intermediate products and sums fit.
type Coordinate = float64

type Point struct {
	X, Y Coordinate
}

func cross(a, b, c Point) Coordinate {
	return (b.X-a.X)*(c.Y-a.Y) - (b.Y-a.Y)*(c.X-a.X)
}

func distanceSquared(a, b Point) Coordinate {
	dx, dy := b.X-a.X, b.Y-a.Y
	return dx*dx + dy*dy
}

// HullInd returns original indices of convex hull vertices in counterclockwise
// order, starting at the lexicographically smallest point (X, then Y).
// It omits repeated coordinates and intermediate collinear boundary points;
// the starting vertex is not repeated at the end. Empty input returns nil.
// The input is not modified. Time: O(n log n); extra space: O(n).
// Like the source, floating-point comparisons are exact, without an epsilon.
func HullInd(points []Point) []int {
	if len(points) == 0 {
		return nil
	}

	pivot := 0
	for i := 1; i < len(points); i++ {
		if points[i].X < points[pivot].X ||
			(points[i].X == points[pivot].X && points[i].Y < points[pivot].Y) {
			pivot = i
		}
	}

	candidates := make([]int, 0, len(points)-1)
	for i := range points {
		if points[i] != points[pivot] {
			candidates = append(candidates, i)
		}
	}

	// All candidates lie in the pivot's right half-plane. Sort by angle,
	// then by increasing distance so collinear nearer points get removed.
	sort.Slice(candidates, func(i, j int) bool {
		a, b := points[candidates[i]], points[candidates[j]]
		turn := cross(points[pivot], a, b)
		if turn != 0 {
			return turn > 0
		}
		return distanceSquared(points[pivot], a) < distanceSquared(points[pivot], b)
	})

	hull := make([]int, 1, len(points))
	hull[0] = pivot
	for _, candidate := range candidates {
		for len(hull) > 1 &&
			cross(points[hull[len(hull)-2]], points[hull[len(hull)-1]], points[candidate]) <= 0 {
			hull = hull[:len(hull)-1]
		}
		hull = append(hull, candidate)
	}
	return hull
}

// Hull returns the hull vertices instead of their original indices.
func Hull(points []Point) []Point {
	indices := HullInd(points)
	if len(indices) == 0 {
		return nil
	}
	result := make([]Point, len(indices))
	for i, index := range indices {
		result[i] = points[index]
	}
	return result
}
