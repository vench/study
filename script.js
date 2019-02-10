
// Hint's
function CreateElement(name, attributes, parent) {
    var el = document.createElement(name);
    for(var key in attributes) {
        if(key === 'text') {
            el.innerText = attributes[key];
        } else {
            el.setAttribute(key, attributes[key]);
        }        
    }
    if(parent) {
        parent.appendChild(el)
    }
    return el;
}

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min)) + min;
}

// class Player
function Player(type) {
    this.type = type || 0;
}

Player.prototype.GetType = function() {
    return this.type;
}

// class StateCeil
function StateCeil(type) {
    this.type = type || 0;
};

StateCeil.prototype.Draw = function(ctx, x, y, w, h) {
    if( this.type == 0) {
        return;
    }
  //  var char =  this.type == 1 ? 'X' : 'O'; 
  //  ctx.fillText(char + ' ' + x + 'x' + y, x * w + w/2, y * h + h/2);
   if(this.type == 2) {
    ctx.beginPath();
    ctx.arc(x * w + w/2, y * h + h/2, h/3, 0, 2 * Math.PI);
    ctx.stroke();
   } else {
    ctx.beginPath();
    ctx.moveTo(x * w + w/3, y * h + h/3);
    ctx.lineTo(x * w + w/2*2, y * h + h/2*2);
    ctx.stroke();
   }
};

//
StateCeil.prototype.SetType = function(type) {
    if(this.IsEmpty()) {
        this.type = type;
        return true;
    }
    return false;   
};

StateCeil.prototype.IsEmpty = function() {
    return this.type === 0;
}


// class StateGame
function StateGame(ceilSize) {
    this.positions = [
        new StateCeil(0),
        new StateCeil(0),
        new StateCeil(0), 
        new StateCeil(0),
        new StateCeil(0),
        new StateCeil(0), 
        new StateCeil(0),
        new StateCeil(0),
        new StateCeil(0)];
    this.ceilSize = ceilSize || 100;    
};

StateGame.prototype.GetState = function(x,y) {
    var ix = Math.floor(x / this.ceilSize),
        iy = Math.floor(y / this.ceilSize),
        index = ix + iy * 3;
    ;
    return this.positions[index] ? this.positions[index] : null;
};

StateGame.prototype.Draw = function(ctx) {
    for(var i = 0; i < 3; i ++) {
        for(var j = 0; j < 3; j ++) {
            var index = i + j * 3; 
            this.positions[index].Draw(ctx, i, j, this.ceilSize, this.ceilSize);
        }
    }
};

// class GAME 
function Game(parent) {
    parent = document.body || parent;

    this.grid = {
        width: 300, height: 300
    };
    CreateElement('h1', {
        'text': 'Крестики нолики', 
    }, parent);
    this.canvas = CreateElement('canvas', {
        'id': 'canvasdummy', 'width': this.grid.width, 'height': this.grid.height, 
    }, parent);  
    this.canvas.addEventListener('click', this.OnHandlerClickCanvas.bind(this), false);

    this.player1 = new Player(1)
    this.player2 = new Player(2)
    this.state = new StateGame();
}

//
Game.prototype.OnHandlerClickCanvas = function(e){
    var x, y, target = e.srcElement || e.target;
    if (e.pageX || e.pageY) { 
        x = e.pageX;
        y = e.pageY;
    }  else { 
        x = e.clientX + document.body.scrollLeft + document.documentElement.scrollLeft; 
        y = e.clientY + document.body.scrollTop + document.documentElement.scrollTop; 
    } 
    x -= target.offsetLeft;
    y -= target.offsetTop; 

    var cell = this.state.GetState(x, y);
    this.Player1Move(cell);
};

Game.prototype.Player1Move = function(posCeil){
    if(this.CheckGameOver()) {
        return this.GameOver();
    }
    if(posCeil && posCeil.SetType(this.player1.GetType())) { 
        this.Draw();
        if(this.CheckGameOver()) {
            return this.GameOver();
        }

        this.Player2Move();
        this.Draw();
        if(this.CheckGameOver()) {
            return this.GameOver();
        }
        
    } else {
        alert("Ход недоступен");
    }
}

//
Game.prototype.Player2Move = function(){
    var availables = [];
    for(var i = 0;i < this.state.positions.length; i ++ ) {
        if(this.state.positions[i].IsEmpty()) {
            availables.push(i);
        }
    }
   
    if(availables.length == 0) {
        return;
    }

    var index = getRandomInt(0, availables.length);
    this.state.positions[availables[index]].SetType(this.player2.GetType());
}

Game.prototype.CheckGameOver = function() {
    var p = this.state.positions;
    for(var i = 0; i < 3; i ++) {
        if(p[i*3+0].type == p[i*3+1].type && 
            p[i*3+1].type && p[i*3+2].type && p[i*3+0].type != 0) {
                return true;
        }
        if(p[i+0].type == p[3+i].type && 
            p[3+i].type == p[6+i].type && p[i*3+0].type != 0) {
                return true;
        }
    }

    if(p[0].type == p[4].type && p[4].type == p[8].type && p[0].type != 0) {
        return true;
    }
    if(p[2].type == p[4].type && p[4].type == p[6].type && p[2].type != 0) {
        return true;
    }
    
    return false;
};    

Game.prototype.GameOver = function() {
    alert("Игра закончена!!!");
};

//
Game.prototype.Draw = function() {
 
    var ctx = this.canvas.getContext("2d");
    ctx.clearRect(0, 0, this.grid.width, this.grid.height);
     
    var len = 3,
        ws = Math.floor(this.grid.width / len),
        hs = Math.floor(this.grid.height / len);
    for(var i = 1; i < len; i ++) {
        ctx.beginPath();
        ctx.moveTo(ws*i, 0);
        ctx.lineTo(ws*i , this.grid.height); 
        ctx.stroke();
        ctx.beginPath();
        ctx.moveTo(0, hs*i);
        ctx.lineTo(this.grid.width , hs*i); 
        ctx.stroke()
    }

    this.state.Draw(ctx);
    
};

Game.prototype.Init = function() {

    this.Draw();
};


window.onload = function() {
    var game = new Game();
    game.Init();
}; 

