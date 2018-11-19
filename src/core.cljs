(window.resizeTo 640 480)
(window.moveTo (/ screen.availWidth 4) (/ screen.availHeight 4))

(m.render document.body
          [(m "h1" "Hello world!")
           (m "button" {:onclick (fn [] (alert "beep"))} "beep")])
