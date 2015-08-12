(def triangle
  (map #(* % (+ % 1) (/ 1 2)) (rest (range))))

(def pentagonal
  (map #(* % (- (* 3 %) 1) (/ 1 2)) (rest (range))))

(def hexagonal
  (map #(* % (- (* 2 %) 1)) (rest (range))))

(defn pentagonal? [x]
  (= 5.0 (mod (Math/sqrt (+ (* 24 x) 1)) 6)))

(defn hexagonal? [x]
  (zero? (mod (/ (inc (Math/sqrt (+ 1 (* 8 x)))) 4) 1)))

(defn p045 []
  (first (filter (every-pred pentagonal? hexagonal?) (nthnext triangle 285))))
