(load-file "sieve.clj")

(defn prime-factors [n]
  (distinct (loop [x n coll [] p (lazy-primes)]
              (let [f (first p) r (rest p)]
                (cond (= x 1) coll
                      (> f (Math/sqrt n)) (conj coll x)
                      (zero? (mod x f)) (recur (/ x f) (conj coll f) p)
                      :else (recur x coll r))))))

(defn p047
  "Evaluates the first of four consecutive integers having four distinct prime factors."
  [] (loop [s 2 c 0 l (lazy-primes)]
                                        ;s contains the current number that is being checked
                                        ;c is the counter
                                        ;l helps taking out test cases where prime is in range
       (let [coll (prime-factors s)]
         (cond (= c 4) (- s 4)
                                        ;if the counter reaches four, return answer
               (< (first l) (+ s (- 3 c))) (recur (inc (first l)) 0 (rest l))
                                        ;if one of the numbers we'll check is prime, reset counter, start from prime + 1
               (= 4 (count coll)) (recur (inc s) (inc c) l)
                                        ;if there are four distinct prime factors for s, check the next number, increment counter
               :else (recur (inc s) 0 l)
                                        ;else, s doesn't have four distinct primes, reset counter, move on to the next one
               ))))
