(load-file "sieve.clj")

(defn prime-factors [n]
  (distinct (loop [x n coll [] p (lazy-primes)]
              (let [f (first p) r (rest p)]
                (cond (= x 1) coll
                      (> f (Math/sqrt n)) (conj coll x)
                      (zero? (mod x f)) (recur (/ x f) (conj coll f) p)
                      :else (recur x coll r))))))

(defn number-of-prime-factors [n]
  )
(defn p047
  "Evaluates the first of four consecutive integers having four distinct prime factors."
  [] (loop [s 2 c 0 l (lazy-primes)]
       (let [coll (prime-factors s)]
         (cond (= c 4) (- s 4)
               (< (first l) (+ s (- 3 c))) (recur (inc (first l)) 0 (rest l))
               (= 4 (count coll)) (recur (inc s) (inc c) l)
               :else (recur (inc s) 0 l)))))
