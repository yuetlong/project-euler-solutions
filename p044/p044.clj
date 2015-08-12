(defn pentagonal? [& args]
  (every? #(zero? (rem (+ 1 (Math/sqrt (+ 1 (* 24 %)))) 6)) args))

(def lazy-pentagonal (map #(/ (- (* 3 % %) %) 2) (iterate inc 1)))

(defn p044 []
  (first (for [j lazy-pentagonal
               k (take-while #(< % j) lazy-pentagonal)
               :when (pentagonal? (- j k) (+ j k))]
           (- j k))))
