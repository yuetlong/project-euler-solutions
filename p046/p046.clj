(load-file "sieve.clj")

(defn not-square? [n]
  (not= 0.0 (mod (Math/sqrt n) 1)))

(defn p046
  "Evaluates the smallest odd composite that cannot be written as the sum of a prime and twice a square. Brute force approach."
  []
  (first (for [odd-composite (odd-composites)
               :let [prime (take-while #(< % odd-composite) (primes))]
               :let [numbers (map #(/ (- odd-composite %) 2) prime)]
               :when (every? not-square? numbers)]
           odd-composite )))
