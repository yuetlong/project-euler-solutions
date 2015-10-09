(defn exp [n x]
  (reduce * (repeat x n)))

(defn digit-count [num]
  (count (str num)))

(defn p063 []
  (count (for [p (range 1N 100N)
               n(range 1N 100N)
               :when (= n (digit-count (exp p n)))]
           (exp p n))))
