(defn p057 []
  (let [expansions (map inc (iterate #((/ 1 (+ 2 %))) (/ 1 2)))]
    (take 10 expansions)))
