function CreateElement(name, attributes, parent) {
    var el = document.createElement(name);
    for(var key in attributes) {
        el.setAttribute(key, attributes[key]);
    }
    if(parent) {
        parent.appendChild(el)
    }
    return el;
}

function Game(parent) {
    parent = document.body || parent;

    this.grid = {
        width: 300, height: 300
    };
    this.canvas = CreateElement('canvas', {
        'id': 'canvasdummy', 'width': this.grid.width, 'height': this.grid.height, 
    }, parent); 

    this.player1 = {}
    this.player2 = {}
    this.state = []
}

Game.prototype.Draw = function() {
 
    var ctx = this.canvas.getContext("2d");
    ctx.beginPath();
    var c = 100;
    for(var i = 0; i < 3; i ++) {
        ctx.moveTo(i*c+c, i*c+c);
        ctx.lineTo(i*c, i*c);
    }
   
    ctx.stroke();
};

Game.prototype.Init = function() {

    this.Draw();
};


window.onload = function() {
    var game = new Game();
    game.Init();
}; 

