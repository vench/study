
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

// class 
var HistoryGame = {
    Data:{}, 
    GetByState: function(stateHash){
        var state = HistoryGame.Data[stateHash];
        if(!state) {
            return -1;
        }

        var mx = 0, index = -1;
        for(var k in state) {
            if(state[k] > mx) {
                index = k;
                mx = state[k];
            }    
        }
        return index;
    },
    Common:[],
    ClearCommon: function() {
        HistoryGame.Common = [];
    },
    SaveCommon: function(typeWin) {
        for(var i = 0; i < HistoryGame.Common.length; i ++) {
            var item = HistoryGame.Common[i];
            if(item.t == typeWin) {
                if(!HistoryGame.Data[item.s]) {
                    HistoryGame.Data[item.s] = {};
                }
                if(!HistoryGame.Data[item.s][item.i]) {
                    HistoryGame.Data[item.s][item.i] = 0;
                }
                HistoryGame.Data[item.s][item.i] ++;
            }
        }
        HistoryGame.Common = [];
    },
    SetCommon: function(stateHash, indexMove, type){
        HistoryGame.Common.push({
            s: stateHash, i: indexMove, t: type
        })
    }
};




// class Player
function Player(type) {
    this.type = type || 0;
}

Player.prototype.GetType = function() {
    return this.type;
}

Player.prototype.TryMove = function(state, useHistory) {
    var stateHash = state.GetStateHash(); 
    var indexHist = HistoryGame.GetByState(stateHash);
    if(useHistory && indexHist >= 0 && state.positions[indexHist].SetType(this.GetType())) {
        HistoryGame.SetCommon(stateHash, indexHist, this.GetType()); 
       // console.log('By hist')
        return true;
    }

    var availables = [];
    for(var i = 0;i < state.positions.length; i ++ ) {
        if(state.positions[i].IsEmpty()) {
            availables.push(i);
        }
    }
   
    if(availables.length == 0) {
        return;
    }

    var index = getRandomInt(0, availables.length);    
    if(state.positions[availables[index]].SetType(this.GetType())) {
        HistoryGame.SetCommon(stateHash, availables[index], this.GetType()); 
        return true;       
    }
    return false;
}


// class StateCeil
function StateCeil(type) {
    this.type = type || 0;
    this.color = undefined;
};

StateCeil.prototype.Draw = function(ctx, x, y, w, h) {
    if( this.type == 0) {
        return;
    } 

   var lineWidth =  ctx.lineWidth;
   var strokeStyle = ctx.strokeStyle; 
   if(!!this.color) {
    ctx.strokeStyle = this.color;
   }
   ctx.lineWidth = 3;
   if(this.type == 2) {
        ctx.beginPath();   
        ctx.arc(x * w + w/2, y * h + h/2, h/3, 0, 2 * Math.PI);
        ctx.stroke();

   } else {
        ctx.beginPath();  
        ctx.moveTo(x * w + w/4, y * h + h/4);
        ctx.lineTo(x * w + w-w/4, y * h + h-h/4);

        ctx.moveTo(x * w + w-w/4, y * h +h/4);
        ctx.lineTo(x * w + w/4, y * h + h-h/4);
        ctx.stroke();    
   }
   ctx.lineWidth = lineWidth;
   ctx.strokeStyle = strokeStyle;
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

StateGame.prototype.GetStateCeilIndex = function(stateCeil){
    for(var i = 0; i < this.positions.length; i ++) {
        if(this.positions[i] === stateCeil) {
            return i;
        }
    }
    return -1;
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

StateGame.prototype.GetStateHash = function(){
    var list = [];
    for(var i = 0; i < 3; i ++) {
        for(var j = 0; j < 3; j ++) {
            var index = i + j * 3; 
            list.push( this.positions[index].type);
        }
    }  
    return list.join('')
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
    var btnNewGame = CreateElement('button', {'text':'Новая игра'}, CreateElement('div', {}, parent)); 
    btnNewGame.addEventListener('click', this.NewGame.bind(this));
    var btnLearn = CreateElement('button', {'text':'Обучить'}, CreateElement('div', {}, parent)); 
    btnLearn.addEventListener('click', this.LearnGame.bind(this));

    this.canvas = CreateElement('canvas', {
        'id': 'canvasdummy', 'width': this.grid.width, 'height': this.grid.height, 
    }, parent); 

    this.canvas.addEventListener('click', this.OnHandlerClickCanvas.bind(this), false);
    
    this.log = CreateElement('div', {}, parent);

    this.NewGame();
}

Game.prototype.Info = function(text) {
    this.log.innerHTML = text;
};

Game.prototype.LearnGame = function(){
    
    var i = 0;
    var t = setInterval(function(){
        var n = 0;
        this.NewGame();
        var players = [];
        if(this.player1.GetType() == 2) {
            players.push(this.player1);
            players.push(this.player2);
        } else {
            players.push(this.player2);
            players.push(this.player1);
        }
        while(!this.CheckGameOver() && n < 10) {
            players[n % 2].TryMove(this.state, Math.random() > .7);
            this.Draw(); 
            n++;
        }
        if(this.CheckGameOver()) {
             this.GameOver();
        }
        if( i ++ > 100000)  {
            clearInterval(t);
        }


    }.bind(this), 10);
};

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
    var stateHash = this.state.GetStateHash();    
    if(posCeil && posCeil.SetType(this.player1.GetType())) { 
        HistoryGame.SetCommon(stateHash, this.state.GetStateCeilIndex(posCeil), this.player1.GetType());
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
        this.Info("Ход недоступен");
    }
}

//
Game.prototype.Player2Move = function(){
    return this.player2.TryMove(this.state, true);
}

Game.prototype.CheckGameOver = function() {
    var p = this.state.positions,
        colorWin = '#f00'
    ;
     
    for(var i = 0; i < 3; i ++) {
        if(p[i*3].type == p[i*3+1].type && 
            p[i*3+1].type == p[i*3+2].type && p[i*3].type != 0) {
                p[i*3+0].color = p[i*3+1].color = p[i*3+2].color = colorWin;
                this.typeWin = p[i*3].type;
                return true;
        }
        if(p[i].type == p[3+i].type && 
            p[3+i].type == p[6+i].type && p[i+3].type != 0) {
                p[i+3].color = p[i+6].color = p[i].color = colorWin;
                this.typeWin = p[i+3].type;
                return true;
        }
    }

    if(p[0].type == p[4].type && p[4].type == p[8].type && p[0].type != 0) {
        p[0].color = p[8].color = p[4].color = colorWin;
        this.typeWin = p[0].type;
        return true;
    }
    if(p[2].type == p[4].type && p[4].type == p[6].type && p[2].type != 0) {
        p[6].color = p[2].color = p[4].color = colorWin;
        this.typeWin = p[2].type;
        return true;
    }
    
    return false;
};    

Game.prototype.NewGame = function() {
    this.player1 = new Player(Math.random() > .5 ? 1 : 2);
    this.player2 = new Player(this.player1.GetType() == 1 ? 2 : 1);
    this.state = new StateGame();
    HistoryGame.ClearCommon();
    this.Init();

    if(this.player1.GetType() == 2) {
        this.Player2Move();
        this.Draw();
    }
}    

Game.prototype.GameOver = function() {
    this.Draw();
    this.Info("Игра закончена!!!" + "\nПобеда: " + 
     (this.typeWin == 1 ? 'X' : 'O') + '!!!');
     HistoryGame.SaveCommon(this.typeWin);
     //console.log(HistoryGame);
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
    this.typeWin = -1;
    this.Draw();
};


window.onload = function() {
    var game = new Game();
    game.Init();
}; 

