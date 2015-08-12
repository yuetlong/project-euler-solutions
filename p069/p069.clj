(defn p069 []
  (letfn [(gcd [a b] (if (zero? b) a (recur b (mod a b))))
          (phi [n] (count (filter #(= 1 (gcd n %)) (range 1 n))))]
    (time (->> (range 2 1001 2)
               (map #(vector % (/ % (phi %))))
               (apply max-key second)
               ))))
